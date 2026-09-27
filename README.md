# Flow-Controlled Inter-Process Communication

Three IPC transport mechanisms — Unix domain sockets, FIFOs, and System V message queues — implementing the same sender/receiver protocol in C, to compare their behavior under an explicit flow-control scheme.

Two programs, **P1** (sender) and **P2** (receiver), communicate over each mechanism:

1. P1 generates 50 random, fixed-length strings.
2. P1 sends them to P2 in batches of 5, each string tagged with its index.
3. P2 receives a batch, prints it, and acknowledges the highest index received.
4. P1 waits for that acknowledgement before sending the next batch — no batch goes out until the previous one is confirmed.

None of the three mechanisms' reliability is assumed. Each implementation has its own explicit error handling and synchronization, rather than relying on guarantees the mechanism doesn't actually make.

## Mechanisms

| Mechanism | Files | Build | Run |
|---|---|---|---|
| Unix domain sockets | `p1.c`, `p2.c` | `make q2_socket` | `./p1`, then `./p2` in another terminal |
| FIFOs (named pipes) | `fifo1.c`, `fifo2.c` | `make q2_fifo` | `./f1`, then `./f2` in another terminal |
| System V message queues | `q1.c`, `q2.c` | `make q2_queue` | `./q2`, then `./q1` in another terminal |

Build everything at once with `make all`.

## Why three mechanisms

- **Sockets** model IPC as a network connection — general-purpose, works across machines, heavier setup.
- **FIFOs** extend the pipe abstraction into a named, filesystem-visible channel between unrelated processes.
- **Message queues** hand buffering and message boundaries to the kernel, avoiding manual delimiter handling.

Implementing the same flow-controlled protocol three times surfaces the real differences between these primitives — connection setup, message-boundary handling, and blocking behavior — rather than just describing them.
