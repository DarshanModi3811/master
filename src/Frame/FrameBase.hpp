#ifndef FRAME_BASE_HPP
#define FRAME_BASE_HPP

#include <vector>

/**
 * @class FrameBase
 * @brief Abstract base class representing a bowling frame.
 *
 * This class provides a common interface for all types of bowling frames,
 * including methods for score calculation, applying bonuses, and handling rolls.
 */
class FrameBase {
public:
    /**
     * @brief Calculates the total score for the frame, including bonuses.
     * @return The total score for the frame.
     */
    virtual int calculateScore() const = 0;

    /**
     * @brief Applies a bonus to the frame (e.g., for strikes or spares).
     * @param bonus The bonus value to apply.
     */
    virtual void applyBonus(int bonus) = 0;

    /**
     * @brief Gets the first roll of the frame.
     * @return The number of pins knocked down in the first roll.
     */
    virtual int getFirstRoll() const = 0;

    /**
     * @brief Gets the second roll of the frame.
     * @return The number of pins knocked down in the second roll.
     */
    virtual int getSecondRoll() const = 0;

    /**
     * @brief Sets the third roll of the frame (used for the 10th frame).
     * @param roll3 The number of pins knocked down in the third roll.
     */
    virtual void setThirdRoll(int roll3) = 0;

    /**
     * @brief Gets the third roll of the frame (used for the 10th frame).
     * @return The number of pins knocked down in the third roll.
     */
    virtual int getThirdRoll() const = 0;

    /**
     * @brief Virtual destructor for the FrameBase class.
     */
    virtual ~FrameBase() {}
};

#endif // FRAME_BASE_HPP
