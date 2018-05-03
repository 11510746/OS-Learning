#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

/**
** Learn how to compute these things 
** at https://www.youtube.com/watch?v=Trd5XxEk2jU
**/
#define ADDR_LEN 28
#define OFFSET_LEN 4
#define INDEX_LEN 6
#define TAG_LEN 18

struct line{
    int valid;
    int tag;
};

int main(){
    struct line cache[(int)pow(2, INDEX_LEN)];
    int i = 0;
    while(INDEX_LEN > i){
        cache[i].valid = 0;
        cache[i].tag = 0;
        i++;
    }


    int query_cnt = 0;
    int hit_cnt = 0;
    float hit_ratio = 0.0;


    while(1){
        //it should be 9 for '\0',but 8 seems to work
        char query[8];
        scanf("%s", &query);

        if( strcmp(query,"END") == 0)
            break;

        query_cnt++;

        int addr = strtol(query, NULL, 16);
        //	printf("addr %x\t", addr);

        int tag = addr >> 10;
        //	printf("tag %x\t", tag);


        int index = (addr >> 4) - (tag << 6);
        //	printf("index %x\t", index);

        int offset = addr - ( (addr >> 4) << 4 );
        //	printf("offset %x\n", offset);


        //	printf("%d %x\n",line.valid, line.tag);

        if(cache[index].valid == 1 && cache[index].tag == tag){
            hit_cnt++;
            puts("Hit");
        }else{
            cache[index].valid = 1;
            cache[index].tag = tag;
            puts("Miss");
            //	printf("After set %d %x\n",line.valid, line.tag);
        }

    }

    printf("Hit ratio = %.2f%%\n", (float)100*hit_cnt/query_cnt);

} 


