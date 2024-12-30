/*
Nama    : I Nyoman Rai Dharma Wiguna
NIM     : 18223083
Tanggal : 29 Desember 2024
*/

#include <stdio.h>
#include "queue.h"

int main()
{
    Queue que_time;
    CreateQueue(&que_time);

    int command, input_time, output_time, min_time, max_time;
    int count = 0;

    scanf("%d", &command);

    while (command != 0)
    {
        if (command == 1 && !isFull(que_time)) // menerima order
        {
            scanf("%d", &input_time);
            
            if (input_time > 0) // time yang valid
            {
                enqueue(&que_time, input_time);
            }
        }
        
        else if (command == 2 && !isEmpty(que_time)) // menyajikan order
        {
            dequeue(&que_time, &output_time);

            count += 1;

            if (count == 1)
            {
                min_time = output_time;
                max_time = output_time;
            } else
            {
                if (output_time < min_time)
                {
                    min_time = output_time;
                } else if (output_time > max_time)
                {
                    max_time = output_time;
                }
            }
        }

        scanf("%d", &command);
    }
    
    printf("%d\n%d\n%d\n", count,min_time,max_time);
}