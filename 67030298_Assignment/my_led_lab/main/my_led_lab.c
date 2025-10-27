#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h" // เพิ่มสำหรับ Lab 2
#include "esp_log.h"

// --- 1 = Lab 1.1 (LED ON)
// --- 2 = Lab 1.2 (LED OFF)
// --- 3 = Lab 1.3 (LED Blink)
// --- 4 = Lab 2   (PWM Breathing)

#define CURRENT_STEP 4

#define LED_GPIO GPIO_NUM_2
static const char *TAG = "ESP32_LAB";

// --- ค่าคงที่สำหรับ Lab 1.3 ---
#define BLINK_PERIOD 1000

// --- ค่าคงที่สำหรับ Lab 2 (PWM) ---
#if CURRENT_STEP == 4
    #define LEDC_TIMER      LEDC_TIMER_0
    #define LEDC_MODE       LEDC_LOW_SPEED_MODE
    #define LEDC_CHANNEL    LEDC_CHANNEL_0
    #define LEDC_DUTY_RES   LEDC_TIMER_13_BIT  // 8192 levels
    #define LEDC_FREQUENCY  5000               // 5kHz
    #define FADE_TIME       3000               // 3 วินาที


void ledc_init(void) {
    // 1. Configure timer
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // 2. Configure channel
    ledc_channel_config_t ledc_channel = {
        .channel    = LEDC_CHANNEL,
        .duty       = 0,
        .gpio_num   = LED_GPIO,
        .speed_mode = LEDC_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_TIMER,
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
    
    // 3. Initialize fade service
    ESP_ERROR_CHECK(ledc_fade_func_install(0));
}
#endif // จบส่วนของ Lab 2

void app_main(void) {

#if CURRENT_STEP == 1
    // --- 🧪 LAB 1.1: LED ON ---
    ESP_LOGI(TAG, "Running Lab 1.1: LED ON");
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_GPIO, 1);
    ESP_LOGI("LED", "LED is ON!");
    while(1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    // --- จบ Lab 1.1 ---

#elif CURRENT_STEP == 2
    // --- 🧪 LAB 1.2: LED OFF ---
    ESP_LOGI(TAG, "Running Lab 1.2: LED ON for 3s, then OFF");
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    gpio_set_level(LED_GPIO, 1);
    ESP_LOGI("LED", "LED is ON for 3 seconds...");
    vTaskDelay(pdMS_TO_TICKS(3000));

    gpio_set_level(LED_GPIO, 0);
    ESP_LOGI("LED", "LED is OFF!");
    while(1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    // --- จบ Lab 1.2 ---

#elif CURRENT_STEP == 3
    // --- 🧪 LAB 1.3: LED BLINK ---
    ESP_LOGI(TAG, "Running Lab 1.3: LED Blink");
    
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    bool led_state = false;

    while (1) {
        led_state = !led_state; // สลับสถานะ
        gpio_set_level(LED_GPIO, led_state);
        ESP_LOGI("LED", "LED is %s", led_state ? "ON" : "OFF");
        vTaskDelay(pdMS_TO_TICKS(BLINK_PERIOD));
    }
    // --- จบ Lab 1.3 ---

#elif CURRENT_STEP == 4
    // --- 🌟 LAB 2: PWM BREATHING ---
    ESP_LOGI(TAG, "Running Lab 2: PWM Breathing Effect");
    ledc_init(); // เรียกใช้ฟังก์ชันที่เตรียมไว้

    while (1) {
        // หายใจเข้า (Fade IN: 0% → 100%)
        ESP_LOGI(TAG, "Breathing IN...");
        ESP_ERROR_CHECK(ledc_set_fade_with_time(LEDC_MODE, LEDC_CHANNEL, 8191, FADE_TIME));
        ESP_ERROR_CHECK(ledc_fade_start(LEDC_MODE, LEDC_CHANNEL, LEDC_FADE_WAIT_DONE));

        // หายใจออก (Fade OUT: 100% → 0%)
        ESP_LOGI(TAG, "Breathing OUT...");
        ESP_ERROR_CHECK(ledc_set_fade_with_time(LEDC_MODE, LEDC_CHANNEL, 0, FADE_TIME));
        ESP_ERROR_CHECK(ledc_fade_start(LEDC_MODE, LEDC_CHANNEL, LEDC_FADE_WAIT_DONE));
    }
    // --- จบ Lab 2 ---

#else
    ESP_LOGE(TAG, "No step selected. Set CURRENT_STEP (1-4) in main.c");
    while(1) {
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
#endif
}

