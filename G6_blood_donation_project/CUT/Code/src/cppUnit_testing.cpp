#include <iostream>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <netinet/in.h>
#include <string>
#include "employee_validation.cpp"
#include "donor_registration.cpp"
#include "manage_donor_data.cpp"
#include "Validation.cpp"


using namespace CppUnit;
using namespace std;

class testdr: public CppUnit::TestFixture
{	
	CPPUNIT_TEST_SUITE(testdr);
	CPPUNIT_TEST(test_donor_registration);
	CPPUNIT_TEST(test_edit_donor_data);
	CPPUNIT_TEST(test_employee_validation);
	CPPUNIT_TEST_SUITE_END();
	
	public:
		void setUp(void);
		void tearDown(void);
	protected:
		void test_donor_registration(void);
		void test_edit_donor_data(void);
		void test_employee_validation(void);
	private:
		donor *myobj1;
};

void testdr::test_donor_registration(void)
{
	CPPUNIT_ASSERT(0==donor_registration());
}

void testdr::test_edit_donor_data(void)
{
	CPPUNIT_ASSERT(0==myobj1->edit_donor_data());
}

void testdr::test_employee_validation(void)
{
	CPPUNIT_ASSERT(0==employee_validation());
}

void testdr::setUp(void)
{
	myobj1=new donor();
}

void testdr::tearDown(void)
{
	delete myobj1;
}

CPPUNIT_TEST_SUITE_REGISTRATION(testdr);

int main(int argc,char* argv[])
{
	CPPUNIT_NS::TestResult testresult;
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults,std::cerr);
	compileroutputter.write();
	return collectedresults.wasSuccessful()?0:1;

}


