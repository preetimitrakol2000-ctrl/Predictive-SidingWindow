#include <stdio.h>
#include "window_queue.h"

int main() {
    printf("🛠️  Activating Predictive-SlidingWindow Diagnostic Framework...\n\n");

    int window_capacity = 3;
    SlidingWindowQueue* structural_logs = init_window_frame(window_capacity);

    // Simulate real-time continuous robotic vibration measurements (in Hz)
    printf("📥 Ingesting Telemetry Streams: 12.0Hz, 14.0Hz, 13.0Hz\n");
    append_sensor_metric(structural_logs, 12.0);
    append_sensor_metric(structural_logs, 14.0);
    append_sensor_metric(structural_logs, 13.0);

    printf("   📊 Current Window Frame Feature Average: %.2f Hz\n", extract_moving_mean(structural_logs));

    // Next element insertion triggers sliding window overwrite behavior dropping historical element (12.0)
    printf("\n📥 Ingesting New Stream Record: 21.0Hz (Triggers Slide Shift)\n");
    append_sensor_metric(structural_logs, 21.0);

    printf("   🔮 Updated Window Moving Feature Average: %.2f Hz\n", extract_moving_mean(structural_logs));

    free_window_frame(structural_logs);
    return 0;
}
