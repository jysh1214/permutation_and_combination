SET(SRCS main.cpp)
SET(INCS ${PROJECT_SOURCE_DIR}/lib)
SET(LIBS PermutationCombinationLib)

INCLUDE_DIRECTORIES(${INCS})
ADD_EXECUTABLE(PermutationCombination ${SRCS})
TARGET_LINK_LIBRARIES(PermutationCombination ${LIBS})
