#include "GeneratorVc2013Winrt.h"
#include "ProjectTemplateManager.h"
#include "Util.h"
#include "Vc2013WinrtProj.h"

#include <fstream>

QMap<QString,QString> GeneratorVc2013WinRt::getConditions() const
{
	QMap<QString,QString> conditions;
	conditions["compiler"] = "vc2013";
	conditions["os"] = "winrt";
	return conditions;
}

QString GeneratorVc2013WinRt::getCompiler() const
{
	return QString( "120" );
}

VcProjRef GeneratorVc2013WinRt::createVcProj( const QString &VcProj, const QString &VcProjFilters )
{
	return Vc2013WinrtProj::createFromString( VcProj, VcProjFilters );
}

std::vector<VcProj::ProjectConfiguration> GeneratorVc2013WinRt::getPlatformConfigurations() const
{
    std::vector<VcProj::ProjectConfiguration> result;

	if( mOptions.mEnableWin32 ) {
		result.push_back( VcProj::ProjectConfiguration( QString::fromUtf8( "Debug" ), QString::fromUtf8( "Win32" ) ) );
		{auto conditions = getConditions(); conditions["arch"] = "i386"; conditions["config"] = "debug";
		result.back().setConditions( conditions );}

		result.push_back( VcProj::ProjectConfiguration( QString::fromUtf8( "Release" ), QString::fromUtf8( "Win32" ) ) );
		{auto conditions = getConditions(); conditions["arch"] = "i386"; conditions["config"] = "release";
		result.back().setConditions( conditions );}
	}

	if( mOptions.mEnableX64 ) {
		result.push_back( VcProj::ProjectConfiguration( QString::fromUtf8( "Debug" ), QString::fromUtf8( "x64" ) ) );
		{auto conditions = getConditions(); conditions["arch"] = "x86_64"; conditions["config"] = "debug";
		result.back().setConditions( conditions );}

		result.push_back( VcProj::ProjectConfiguration( QString::fromUtf8( "Release" ), QString::fromUtf8( "x64" ) ) );
		{auto conditions = getConditions(); conditions["arch"] = "x86_64"; conditions["config"] = "release";
		result.back().setConditions( conditions );}
	}

	if( mOptions.mEnableArm ) {
		result.push_back( VcProj::ProjectConfiguration( QString::fromUtf8( "Debug" ), QString::fromUtf8( "ARM" ) ) );
		{auto conditions = getConditions(); conditions["arch"] = "ARM"; conditions["config"] = "debug";
		result.back().setConditions( conditions );}

		result.push_back( VcProj::ProjectConfiguration( QString::fromUtf8( "Release" ), QString::fromUtf8( "x64" ) ) );
		{auto conditions = getConditions(); conditions["arch"] = "ARM"; conditions["config"] = "ARM";
		result.back().setConditions( conditions );}
	}

	return result;
}

bool GeneratorVc2013WinRt::getSlnDeploy() const
{
	return true;
}
