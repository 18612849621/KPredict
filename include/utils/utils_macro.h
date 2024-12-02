#pragma once

#define DISALLOW_COPY_AND_ASSIGN(Classname)                                                 \
  Classname(const Classname &) = delete;                                       \
  Classname &operator=(const Classname &) = delete;                            \
  Classname(Classname &&) = delete;                                            \
  Classname &operator=(Classname &&) = delete

