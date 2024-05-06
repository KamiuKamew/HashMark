#ifndef TESTHEAD_H
#define TESTHEAD_H

#ifndef Testing
#define Testing true
#endif

#if Testing == true
#define TestCode(x) x
#else
#define TestCode(x)
#endif // Testing

#endif // TESTHEAD_H
