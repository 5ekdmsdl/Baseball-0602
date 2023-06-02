#include "pch.h"
#include <string>
#include <gtest/gtest.h>
#include "../BestReview/Baseball.cpp"

TEST(Test, of21)
{
	Baseball bb("123");
	EXPECT_THROW(bb.guess(""), std::invalid_argument);
	EXPECT_THROW(bb.guess("1365"), std::invalid_argument);
	EXPECT_THROW(bb.guess("1v5"), std::invalid_argument);
	EXPECT_THROW(bb.guess("121"), std::invalid_argument);
}

TEST(Test, B3)
{
	Baseball bb("123");
	Result res = bb.guess("312");

	EXPECT_EQ(false, res.solved);
	EXPECT_EQ(0, res.strikes);
	EXPECT_EQ(3, res.balls);
}

TEST(Test, B2S1)
{
	Baseball bb("123");
	Result res = bb.guess("132");

	EXPECT_EQ(false, res.solved);
	EXPECT_EQ(1, res.strikes);
	EXPECT_EQ(2, res.balls);
}

TEST(Test, S3)
{
	Baseball bb("123");
	Result res = bb.guess("123");

	EXPECT_EQ(true, res.solved);
	EXPECT_EQ(3, res.strikes);
	EXPECT_EQ(0, res.balls);
}

TEST(Test, B2_B1_B0)
{
	Baseball bb("123");

	Result res = bb.guess("012");
	EXPECT_EQ(false, res.solved);
	EXPECT_EQ(0, res.strikes);
	EXPECT_EQ(2, res.balls);

	res = bb.guess("052");
	EXPECT_EQ(false, res.solved);
	EXPECT_EQ(0, res.strikes);
	EXPECT_EQ(1, res.balls);

	res = bb.guess("056");
	EXPECT_EQ(false, res.solved);
	EXPECT_EQ(0, res.strikes);
	EXPECT_EQ(0, res.balls);
}
