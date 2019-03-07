#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include"pilote.h"

using namespace testing;

TEST(TestPiloteConstructor, Default)
{
    Pilote pilote;
    ASSERT_TRUE(false);
}
