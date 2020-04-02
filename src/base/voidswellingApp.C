#include "voidswellingApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
voidswellingApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

voidswellingApp::voidswellingApp(InputParameters parameters) : MooseApp(parameters)
{
  voidswellingApp::registerAll(_factory, _action_factory, _syntax);
}

voidswellingApp::~voidswellingApp() {}

void
voidswellingApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"voidswellingApp"});
  Registry::registerActionsTo(af, {"voidswellingApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
voidswellingApp::registerApps()
{
  registerApp(voidswellingApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
voidswellingApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  voidswellingApp::registerAll(f, af, s);
}
extern "C" void
voidswellingApp__registerApps()
{
  voidswellingApp::registerApps();
}
