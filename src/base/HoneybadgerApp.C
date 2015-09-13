#include "HoneybadgerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<HoneybadgerApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

HoneybadgerApp::HoneybadgerApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  HoneybadgerApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  HoneybadgerApp::associateSyntax(_syntax, _action_factory);
}

HoneybadgerApp::~HoneybadgerApp()
{
}

// External entry point for dynamic application loading
extern "C" void HoneybadgerApp__registerApps() { HoneybadgerApp::registerApps(); }
void
HoneybadgerApp::registerApps()
{
  registerApp(HoneybadgerApp);
}

// External entry point for dynamic object registration
extern "C" void HoneybadgerApp__registerObjects(Factory & factory) { HoneybadgerApp::registerObjects(factory); }
void
HoneybadgerApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void HoneybadgerApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { HoneybadgerApp::associateSyntax(syntax, action_factory); }
void
HoneybadgerApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
