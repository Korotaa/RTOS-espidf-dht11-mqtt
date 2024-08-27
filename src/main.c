#include <mqtt_client.h>
#include "protocol_examples_common.h"
#include <esp_event.h>
#include <nvs_flash.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

static void mqttEventHandler(esp_mqtt_handle_t event)
{
    esp_mqtt_handle_t client = event->client;
    if(event->event_id == MQTT_EVENT_CONNECTED)
    {
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED").
        esp_mqtt_client_subscribe(client, "topic", 0);
        ESP_LOGI(TAG3, "Sent subscribe successful");
    }
    else if(event->event_id == MQTT_EVENT_DISCONNECTED)
    {
        ESP_LOGI(TAG3, "MQTT_EVENT_DISCONNECTED");
    }
    else if(event->event_id == MQTT_EVENT_SUBSCRIBED)
    {
        ESP_LOGI(TAG3, "MQTT_EVENT_SUBSCRIBED");
    }
    else if(event->event_id == MQTT_EVENT_UNSUBSCRIBED)
    {
        ESP_LOGI(TAG3, "MQTT_EVENT_UNSUBSCRIBED");
    }
    
    else if(event->event_id == MQTT_EVENT_DATA)
    {
        ESP_LOGI(TAG3, "MQTT_EVENT_DATA");
    }
    //if any other error 
    else if(event->event_id == MQTT_EVENT_ERROR)
    {
        ESP_LOGI(TAG3, "MQTT_EVENT_ERROR");
    }
}




void app_main() {}