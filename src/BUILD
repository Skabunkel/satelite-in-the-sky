
cc_binary(
  name = "satelite-in-the-sky",
  srcs = [
    "main.c",
    "libs/shared.h",
    "libs/component/component.h",
    "libs/component/component.c",
    "libs/tree/tree.h",
    "libs/tree/tree.c",
    "libs/probe/probe.h",
    "libs/probe/probe.c"
    ]
)

cc_test(
  name = "rb-tree-root-insertion",
  srcs = [
    "libs/tree/tests/root-insertion.c",
    "libs/tree/tree.h",
    "libs/tree/tree.c",
    "libs/shared.h"
    ]
)

cc_test(
  name = "rb-tree-null-and-singel-rotation-test",
  srcs = [
    "libs/tree/tests/null-and-singel-rotation.c",
    "libs/tree/tree.h",
    "libs/tree/tree.c",
    "libs/shared.h"
    ]
)

cc_test(
  name = "rb-tree-two-node-rotation-test",
  srcs = [
    "libs/tree/tests/two-node-rotation.c",
    "libs/tree/tree.h",
    "libs/tree/tree.c",
    "libs/shared.h"
    ]
)

cc_test(
  name = "rb-tree-three-node-rotation-test",
  srcs = [
    "libs/tree/tests/three-node-rotation.c",
    "libs/tree/tree.h",
    "libs/tree/tree.c",
    "libs/shared.h"
    ]
)