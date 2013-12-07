// Copyright (c) 2013 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#ifndef EOS_AGENT_H
#define EOS_AGENT_H

#include <eos/base.h>

namespace eos {

void EOS_SDK_PUBLIC
agent_main_loop(const char * agent_name, int argc, char ** argv);

};


#endif // EOS_AGENT_H
