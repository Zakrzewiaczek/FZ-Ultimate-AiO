#ifndef HELPER_H
#define HELPER_H

/**
 * @brief A utility class with helper functions.
 */
class Helper
{
    Helper() = delete;
    Helper(Helper const &) = delete;
    void operator=(Helper const &) = delete;

public:
    /**
     * @brief Converts an unsigned long number to a boolean array representation.
     * @details For numbers less than 16, the result is padded with leading false values to always return 4 bits.
     *          The returned array is allocated on the heap; the caller is responsible for deallocating it using delete[].
     * @param num The number to be converted.
     * @param size Reference to an integer where the size of the resulting boolean array will be stored.
     * @return A pointer to the boolean array representing the binary form of the input number.
     */
    static bool *convertToBoolArray(unsigned long num, int *size);
};

#endif // HELPER_H