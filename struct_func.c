#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/sysctl.h>



struct RECT_BOWL
{
    int x;
    int y;
};

struct ROUND_BOWL
{
    int diameter;
};

//feed a dog
typedef struct FeedDog {
    void* bowl;
    int is_round;
    char* dog_name;
    int (*get_bowl)(struct FeedDog*);
    int (*put_food)(char*);
};

//i wanna to get a bowl to obtain the food
int get_bowl(struct FeedDog* fdg)
{
    if(!fdg){
        printf("%s\n", "I donnt think you wanna to feed dog, please go away.\n");
        return -1;
    }
    
    //round bowl is cheaper
    fdg->bowl = (void*)malloc(sizeof(struct ROUND_BOWL));
    if(fdg->bowl) {
        ((struct ROUND_BOWL*)(fdg->bowl))->diameter = 10;
        fdg->is_round = 1;
        printf("%s\n", "get a round bowl\n");
        return 0;
    }
    //i only get a rectangle bowl
    else {
        fdg->bowl = (void*)malloc(sizeof(struct RECT_BOWL));
        ((struct RECT_BOWL*)(fdg->bowl))->x = 10;
        ((struct RECT_BOWL*)(fdg->bowl))->y = 20;
        fdg->is_round = 0;
        printf("%s\n", "get a rect bowl\n");
        return 0;
    }
}

int put_food (char* food)
{
    printf("%s is in bowl\n", food);
}

struct FeedDog IFD = {
    .dog_name = "AnPie",
    .get_bowl = get_bowl,
    .put_food = put_food,
};

int main()
{
    IFD.get_bowl(&IFD);
    IFD.put_food("pumpkin");
    printf("bowl: %d\n", IFD.is_round);
    return 0;
}
