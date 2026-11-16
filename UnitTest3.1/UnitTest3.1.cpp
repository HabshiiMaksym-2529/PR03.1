#include "pch.h"
#include "CppUnitTest.h"
#include "E:\Документи\навчання\2 курс ООП\PR3.x\PR3.1\Pair.h"
#include "E:\Документи\навчання\2 курс ООП\PR3.x\PR3.1\Pair.cpp"
#include "E:\Документи\навчання\2 курс ООП\PR3.x\PR3.1\RightAngled.h"
#include "E:\Документи\навчання\2 курс ООП\PR3.x\PR3.1\RightAngled.cpp"
#include "E:\Документи\навчання\2 курс ООП\PR3.x\PR3.1\PR3.1.cpp"

#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RightAngledTests
{
    TEST_CLASS(RightAngledTests)
    {
    public:
        TEST_METHOD(BaseReference_RejectsInvalidTriangleLeg)
        {
            RightAngled triangle(3.0, 4.0);
            Pair& base = triangle;

            Assert::AreEqual(12.0, base.Product(), 1e-12);

            Assert::ExpectException<std::invalid_argument>([&base]()
                {
                    base.SetFirst(-1.0);
                });

            Assert::AreEqual(3.0, base.GetFirst(), 1e-12);
            Assert::AreEqual(4.0, base.GetSecond(), 1e-12);
            Assert::AreEqual(5.0, triangle.Hypotenuse(), 1e-12);
        }
    };
}