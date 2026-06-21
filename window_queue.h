#ifndef WINDOW_QUEUE_H
#define WINDOW_QUEUE_H

typedef struct {
    double* log_pool;
    int capacity;
    int current_size;
    int insert_idx;
} SlidingWindowQueue;

SlidingWindowQueue* init_window_frame(int capacity);
void append_sensor_metric(SlidingWindowQueue* sw, double sensor_reading);
double extract_moving_mean(SlidingWindowQueue* sw);
void free_window_frame(SlidingWindowQueue* sw);

#endif
