#ifndef TESTING_UTILS
#define TESTING_UTILS

template<typename T>
void VerboseAssertEqual(T obj1, T obj2) {
    EXPECT_TRUE(obj1 == obj2) << "expected: " << obj1 << " expected: " << obj2 << std::endl;
};

#endif