#include <stdio.h>

enum weekday{Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int main(){
    // By default the datatype of enum is int
    printf("%d\n", Sun);
    // Can assign to variable:
    enum weekday today = Wed;
    today = 12345;
    printf("%d\n", today);

    switch (today){
        case Mon:
            printf("Today is Monday\n");
            break;
        case Wed:
            printf("Today is Wednesday\n");
            break;
        default:
            printf("Today is neither Monday nor Friday\n");
            break;
    }


    return 0;
}

// Enums are the tool to group set of related values together
// The values that follow is incremented by 1, starting from 0. Also if assigned custom value, the next value will be incremented from that value.
// A feature of enum is when compile the file using -Wall, will show warning if the enum is not used in the switch statement unless default is used.

// In the above example running in C might not show error when reassigned the 'today' value to some garbage.
// but when g++ is used, it will show error: 'today' is not a member of 'enum weekday'. Since we can't reassign anything to enum variables. 