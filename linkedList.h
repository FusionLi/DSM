struct statistic{
    int width;
    int count;
    struct statistic *next;
};

void Update(struct statistic**, int);
void Print(struct statistic*, FILE*, int);
void Destroy(struct statistic*);
