
#include <unity.h>
#include "MusicPlayer.h"
#include <stdexcept>

void setUp() {}
void tearDown() {}

void test_default_volume() {
    MusicPlayer controller;
    TEST_ASSERT_EQUAL_INT(50, controller.getVolume());


}
void test_set_volume() {
    MusicPlayer controller;
    controller.setVolume(70);
    TEST_ASSERT_EQUAL_INT(70,controller.getVolume());
}
void test_volume_above_max() {
    MusicPlayer controller;
    controller.setVolume(120);
    TEST_ASSERT_EQUAL_INT(100,controller.getVolume());

}
void test_volume_below_min() {
    MusicPlayer controller;
    controller.setVolume(-20);
    TEST_ASSERT_EQUAL_INT(0,controller.getVolume());
}
void test_volume_at_min() {
    MusicPlayer controller;
    controller.setVolume(0);
    TEST_ASSERT_EQUAL_INT(0,controller.getVolume());
}
void test_volume_at_max() {
    MusicPlayer controller;
    controller.setVolume(100);
    TEST_ASSERT_EQUAL_INT(100,controller.getVolume());
}

void test_empty_library() {
    MusicPlayer library;
    TEST_ASSERT_EQUAL_INT(0, library.getTrackCount());
}

void test_add_single_track() {
    MusicPlayer library;
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_INT(1, library.getTrackCount());
}

void test_add_multiple_tracks() {
    MusicPlayer library;
    library.addTrack("sample.mp3");
    library.addTrack("sample(1).mp3");
    library.addTrack("sample(2).mp3");
    TEST_ASSERT_EQUAL_INT(3, library.getTrackCount());


}

void test_duplicate_track() {
    MusicPlayer library;
    library.addTrack("sample.mp3");
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_INT(1, library.getTrackCount());

}

void test_duplicate_after_other_tracks() {
    MusicPlayer library;
    library.addTrack("sample.mp3");
    library.addTrack("sample(1).mp3");
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_INT(2, library.getTrackCount());

}

void test_case_sensitive_names() {
    MusicPlayer library;
    library.addTrack("sample.mp3");
    library.addTrack("Sample.mp3");
    TEST_ASSERT_EQUAL_INT(2, library.getTrackCount());

}
void test_empty_track_name() {
    MusicPlayer library;
    
    library.addTrack("");
    TEST_ASSERT_EQUAL_INT(0, library.getTrackCount());
}
void test_get_track() {
    MusicPlayer library;
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_STRING("sample.mp3", library.getTrack(0).c_str());
}
void test_get_track_invalid_index() {
    MusicPlayer library;
    try {
        library.getTrack(5);
        TEST_FAIL_MESSAGE("Expected exception was not thrown");
    }
    catch (const std::out_of_range& e) {
    
    }

}
int main() {
    UNITY_BEGIN();
 
    RUN_TEST(test_default_volume);
    RUN_TEST(test_set_volume);
    RUN_TEST(test_volume_above_max);
    RUN_TEST(test_volume_below_min);
    RUN_TEST(test_volume_at_max);
    RUN_TEST(test_volume_at_min);
    
    RUN_TEST(test_empty_library);
    RUN_TEST(test_add_single_track);
    RUN_TEST(test_add_multiple_tracks);
    RUN_TEST(test_duplicate_track);
    RUN_TEST(test_duplicate_after_other_tracks);
    RUN_TEST(test_case_sensitive_names);
    RUN_TEST(test_empty_track_name);
    RUN_TEST(test_get_track);
    RUN_TEST(test_get_track_invalid_index);

    return UNITY_END();
}
