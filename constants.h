#ifndef CONSTANTS_H
#define CONSTANTS_H

// QUESTION ==> SHOULD I NEED TO ADD INLINE KEYWORD
// constexpr --> evaluated at compile time !!
// namespaces --> Does not encapsulate data or behavior, does not directly consume memory. It only provides scope.
namespace constants{

    constexpr int WIDTH {30};
    constexpr int HEIGHT {20};
    constexpr int TILE_SIZE {20};
    constexpr int TICK_INTERVAL {120}; // ms
    constexpr int W_SIZE {WIDTH*TILE_SIZE};
    constexpr int H_SIZE {HEIGHT*TILE_SIZE};
}
#endif // CONSTANTS_H
