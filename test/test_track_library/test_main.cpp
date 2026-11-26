#include <unity.h>
#include "TrackLibrary.h"
#include <stdexcept>

void setUp() {}
void tearDown() {}

void test_empty_library() {
    TrackLibrary library;
    TEST_ASSERT_EQUAL_INT(0, library.getTrackCount());
}

void test_add_single_track() {
    TrackLibrary library;
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_INT(1, library.getTrackCount());
}

void test_add_multiple_tracks() {
    TrackLibrary library;
    library.addTrack("sample.mp3");
    library.addTrack("sample(1).mp3");
    library.addTrack("sample(2).mp3");
    TEST_ASSERT_EQUAL_INT(3, library.getTrackCount());


}

void test_duplicate_track() {
    TrackLibrary library;
    library.addTrack("sample.mp3");
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_INT(1, library.getTrackCount());

}

void test_duplicate_after_other_tracks() {
    TrackLibrary library;
    library.addTrack("sample.mp3");
    library.addTrack("sample(1).mp3");
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_INT(2, library.getTrackCount());

}

void test_case_sensitive_names() {
    TrackLibrary library;
    library.addTrack("sample.mp3");
    library.addTrack("Sample.mp3");
    TEST_ASSERT_EQUAL_INT(2, library.getTrackCount());

}
void test_empty_track_name() {
    TrackLibrary library;
    
    library.addTrack("");
    TEST_ASSERT_EQUAL_INT(0, library.getTrackCount());
}
void test_get_track() {
    TrackLibrary library;
    library.addTrack("sample.mp3");
    TEST_ASSERT_EQUAL_STRING("sample.mp3", library.getTrack(0).c_str());
}
void test_get_track_invalid_index() {
    TrackLibrary library;
    try {
        library.getTrack(5);
        TEST_FAIL_MESSAGE("Expected exception was not thrown");
    }
    catch (const std::out_of_range& e) {
    
    }

}
int main() {
    UNITY_BEGIN();

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