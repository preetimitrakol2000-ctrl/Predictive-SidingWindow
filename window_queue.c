#include <stdlib.h>
#include "window_queue.h"

SlidingWindowQueue* init_window_frame(int capacity) {
    SlidingWindowQueue* sw = (SlidingWindowQueue*)malloc(sizeof(SlidingWindowQueue));
    sw->log_pool = (double*)malloc(capacity * sizeof(double));
    sw->capacity = capacity;
    sw->current_size = 0;
    sw->insert_idx = 0;
    return sw;
}

void append_sensor_metric(SlidingWindowQueue* sw, double sensor_reading) {
    sw->log_pool[sw->insert_idx] = sensor_reading;
    sw->insert_idx = (sw->insert_idx + 1) % sw->capacity; // Overwrite step pattern

    if (sw->current_size < sw->capacity) {
        sw->current_size++;
    }
}

double extract_moving_mean(SlidingWindowQueue* sw) {
    if (sw->current_size == 0) return 0.0;
    double accumulator = 0.0;
    for (int i = 0; i < sw->current_size; i++) {
        accumulator += sw->log_pool[i];
    }
    return accumulator / sw->current_size;
}

void free_window_frame(SlidingWindowQueue* sw) {
    free(sw->log_pool);
    free(sw);
}
