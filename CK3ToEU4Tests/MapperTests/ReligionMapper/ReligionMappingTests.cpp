#include "../../CK3ToEU4/Source/Mappers/ReligionMapper/ReligionMapping.h"
#include "gtest/gtest.h"

TEST(Mappers_ReligionMappingTests, eu4ReligionDefaultsToBlank)
{
	std::stringstream input;
	const mappers::ReligionMapping theMapping(input);

	ASSERT_TRUE(theMapping.getEU4Religion().empty());
}

TEST(Mappers_ReligionMappingTests, eu4ReligionCanBeSet)
{
	std::stringstream input;
	input << "= { eu4 = eu4Religion }";
	const mappers::ReligionMapping theMapping(input);

	ASSERT_EQ("eu4Religion", theMapping.getEU4Religion());
}

TEST(Mappers_ReligionMappingTests, ck3ReligionsDefaultToEmpty)
{
	std::stringstream input;
	const mappers::ReligionMapping theMapping(input);

	ASSERT_TRUE(theMapping.getCK3Religions().empty());
}

TEST(Mappers_ReligionMappingTests, ck3ReligionsCanBeSet)
{
	std::stringstream input;
	input << "= { ck3 = religion1 ck3 = religion2 }";

	const mappers::ReligionMapping theMapping(input);

	ASSERT_EQ(2, theMapping.getCK3Religions().size());
	ASSERT_EQ("religion1", *theMapping.getCK3Religions().find("religion1"));
	ASSERT_EQ("religion2", *theMapping.getCK3Religions().find("religion2"));
}

TEST(Mappers_ReligionMappingTests, eu4SchoolDefaultsToNullopt)
{
	std::stringstream input;
	const mappers::ReligionMapping theMapping(input);

	ASSERT_EQ(std::nullopt, theMapping.getEU4School());
}

TEST(Mappers_ReligionMappingTests, eu4SchoolCanBeSet)
{
	std::stringstream input;
	input << "= { school = some_school }";
	const mappers::ReligionMapping theMapping(input);

	ASSERT_EQ("some_school", *theMapping.getEU4School());
}
