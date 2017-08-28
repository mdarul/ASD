//
// Created by michal on 28/08/17.
//

#ifndef OTHER_DYNAMIC_H
#define OTHER_DYNAMIC_H

struct Activity
{
    int id; // assuming that id != -1
    int start_time, end_time;
};

int longest_common_subsequence(char *tab1, char *tab2, int n, int m);
void activity_selection_problem(Activity *activities, int n);

#endif //OTHER_DYNAMIC_H
