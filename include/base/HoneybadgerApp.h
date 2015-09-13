#ifndef HONEYBADGERAPP_H
#define HONEYBADGERAPP_H

#include "MooseApp.h"

class HoneybadgerApp;

template<>
InputParameters validParams<HoneybadgerApp>();

class HoneybadgerApp : public MooseApp
{
public:
  HoneybadgerApp(InputParameters parameters);
  virtual ~HoneybadgerApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* HONEYBADGERAPP_H */
