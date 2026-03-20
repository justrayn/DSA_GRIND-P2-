void sortQueueue(queue *q){
    Queue *sortQ = init();

    while(!isempty(q)){
        int minval = dequeue(q);
        Queue *tempQ = init();
        while(!isEmpty(q)){
            int curr = dequeue(q);
            if(curr < minval){
                enqueue(tempQ, minval);
                minval = curr;
            } else {
                enqueue(tempQ, curr);
            }
        }

        while(!isEmpty(tempQ)){
            enqueue(q, dequeue(tempQ));
        }

        free(tempQ);

        enqueue(Sort, minval);
    }


    while(!isEmpty(sortQ)){
        enqueue(q, dequeu(sortQ));
    }
}