#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> round_down_scores;
    for(int i = 0; i < student_scores.size(); ++i){
        round_down_scores.emplace_back(static_cast<int>(student_scores.at(i)));
    }
    return round_down_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int passing_score = 40;
    int count = 0;

    for(int score : student_scores){
        if(score <= passing_score){
            count++;
        }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int range = highest_score - 40;
    int increment = range/4;
    std::array<int, 4> letter_grades;
    letter_grades[0] = 41;
    for(int i = 1; i < letter_grades.size(); ++i){
        letter_grades[i] = letter_grades[i - 1] + increment;
    }

    return letter_grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> student_ranking;
    for(int i = 0; i < student_scores.size(); ++i){
        student_ranking.emplace_back(std::to_string(i+1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i)));
    }
    return student_ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {

    for(int i = 0; i < student_scores.size(); ++i){
        if(student_scores.at(i) == 100){
            return student_names.at(i);
        }
    }
    
    return "";
}
