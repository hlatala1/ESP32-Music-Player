#include <unity.h>
#include "VolumeController.h"

void setUp() {}
void tearDown() {}

void test_default_volume() {
    VolumeController controller;
    TEST_ASSERT_EQUAL_INT(50, controller.getVolume());


}
void test_set_volume() {
    VolumeController controller;
    controller.setVolume(70);
    TEST_ASSERT_EQUAL_INT(70,controller.getVolume());
}
void test_volume_above_max() {
    VolumeController controller;
    controller.setVolume(120);
    TEST_ASSERT_EQUAL_INT(100,controller.getVolume());

}
void test_volume_below_min() {
    VolumeController controller;
    controller.setVolume(-20);
    TEST_ASSERT_EQUAL_INT(0,controller.getVolume());
}
void test_volume_at_min() {
    VolumeController controller;
    controller.setVolume(0);
    TEST_ASSERT_EQUAL_INT(0,controller.getVolume());
}
void test_volume_at_max() {
    VolumeController controller;
    controller.setVolume(100);
    TEST_ASSERT_EQUAL_INT(100,controller.getVolume());
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_default_volume);
    RUN_TEST(test_set_volume);
    RUN_TEST(test_volume_above_max);
    RUN_TEST(test_volume_below_min);
    RUN_TEST(test_volume_at_max);
    RUN_TEST(test_volume_at_min);
    return UNITY_END();
}