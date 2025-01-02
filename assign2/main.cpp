/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

#include "utils.h"

std::string kYourName = "Bonnie Rivers"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream file(filename);
  std::string line;
  std::unordered_set<std::string> applicants;
  while (std::getline(file, line)) {
    applicants.insert(line);
  }

  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::cout << "name: " << name << std::endl;
  auto get_initials = [](const std::string& name) ->std::string {
    auto pos = name.find(" ");
    if (pos == std::string::npos) {
      return "";
    }
    std::string initials;
    initials.push_back(name[0]);
    initials.push_back(name[pos + 1]);
    return initials;
  };

  std::queue<const std::string*> matches;
  auto name_initials = get_initials(name);
  for (const auto& student : students) {
    if (get_initials(student) == name_initials) {
      matches.push(&student);
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.'
  std::string result = "NO MATCHES FOUND";
  while (!matches.empty()) {
    const auto& name = matches.front();
    matches.pop();
    std::cout << *name << std::endl;
    if (*name == kYourName) {
      result = kYourName;
      break;
    }
  }
  return result;
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }
