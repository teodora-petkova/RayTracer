#pragma warning(push, 0)
#include "gtest\gtest.h"
#pragma warning(pop)
#include "source\triangle.h"

class TriangleTests : public ::testing::Test
{
protected:
	MaterialPtr material;

	TriangleTests() {
	}

	virtual ~TriangleTests() {
	}

protected:
	void SetUp() override {
		this->material = std::make_shared<Material>(Material(Color(1, 1, 1), 0.1f, 0.9f, 0.9f, 200.0f));
	}
};


TEST_F(TriangleTests, The_ray_is_parallel_to_the_triangle) {
	Triangle t = Triangle(
		Tuple::Point(0, 1, 0),
		Tuple::Point(-1, 0, 0),
		Tuple::Point(1, 0, 0),
		this->material);
	Ray ray = Ray(Tuple::Point(0, -1, -2), Tuple::Vector(0, 1, 0));
	IntersectionInfo intersection = t.Intersect(ray);
	EXPECT_EQ(intersection.getIsHit(), false);
}

TEST_F(TriangleTests, The_ray_misses_AC_traingle_edge) {
	Triangle t = Triangle(
		Tuple::Point(0, 1, 0),
		Tuple::Point(-1, 0, 0),
		Tuple::Point(1, 0, 0),
		this->material);
	Ray ray = Ray(Tuple::Point(1, 1, -2), Tuple::Vector(0, 0, 1));
	IntersectionInfo intersection = t.Intersect(ray);
	EXPECT_EQ(intersection.getIsHit(), false);
}

TEST_F(TriangleTests, The_ray_misses_AB_traingle_edge) {
	Triangle t = Triangle(
		Tuple::Point(0, 1, 0),
		Tuple::Point(-1, 0, 0),
		Tuple::Point(1, 0, 0),
		this->material);
	Ray ray = Ray(Tuple::Point(-1, 1, -2), Tuple::Vector(0, 0, 1));
	IntersectionInfo intersection = t.Intersect(ray);
	EXPECT_EQ(intersection.getIsHit(), false);
}

TEST_F(TriangleTests, The_ray_misses_BC_traingle_edge) {
	Triangle t = Triangle(
		Tuple::Point(0, 1, 0),
		Tuple::Point(-1, 0, 0),
		Tuple::Point(1, 0, 0),
		this->material);
	Ray ray = Ray(Tuple::Point(0, -1, -2), Tuple::Vector(0, 0, 1));
	IntersectionInfo intersection = t.Intersect(ray);
	EXPECT_EQ(intersection.getIsHit(), false);
}

TEST_F(TriangleTests, The_ray_intersects_the_triangle) {
	Triangle t = Triangle(
		Tuple::Point(0, 1, 0),
		Tuple::Point(-1, 0, 0),
		Tuple::Point(1, 0, 0),
		this->material);
	Ray ray = Ray(Tuple::Point(0, 0.5, -2), Tuple::Vector(0, 0, 1));
	IntersectionInfo intersection = t.Intersect(ray);
	EXPECT_EQ(intersection.getIsHit(), true);
	EXPECT_EQ(intersection.getIntersectionPoint(), Tuple::Point(0, 0.5, 0));
	EXPECT_EQ(intersection.getDistance(), 2);
	EXPECT_EQ(intersection.getNormal(), Tuple::Vector(0, 0, 1));
}
