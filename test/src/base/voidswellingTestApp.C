//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "voidswellingTestApp.h"
#include "voidswellingApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
voidswellingTestApp::validParams()
{
  InputParameters params = voidswellingApp::validParams();
  return params;
}

voidswellingTestApp::voidswellingTestApp(InputParameters parameters) : MooseApp(parameters)
{
  voidswellingTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

voidswellingTestApp::~voidswellingTestApp() {}

void
voidswellingTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  voidswellingApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"voidswellingTestApp"});
    Registry::registerActionsTo(af, {"voidswellingTestApp"});
  }
}

void
voidswellingTestApp::registerApps()
{
  registerApp(voidswellingApp);
  registerApp(voidswellingTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
voidswellingTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  voidswellingTestApp::registerAll(f, af, s);
}
extern "C" void
voidswellingTestApp__registerApps()
{
  voidswellingTestApp::registerApps();
}
