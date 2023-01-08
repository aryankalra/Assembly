#include <stdint.h>
#include <stdlib.h>

  000000000040151a <bombphase_1>:
  40151a:       48 83 ec 08             sub    $0x8,%rsp
  40151e:       80 3f 66                cmpb   $0x66,(%rdi)
  401521:       75 3b                   jne    40155e <bombphase_1+0x44>
  401523:       80 7f 03 53             cmpb   $0x53,0x3(%rdi)
  401527:       75 35                   jne    40155e <bombphase_1+0x44>
  401529:       80 7f 01 37             cmpb   $0x37,0x1(%rdi)
  40152d:       75 2f                   jne    40155e <bombphase_1+0x44>
  40152f:       80 7f 04 30             cmpb   $0x30,0x4(%rdi)
  401533:       75 29                   jne    40155e <bombphase_1+0x44>
  401535:       80 7f 02 60             cmpb   $0x60,0x2(%rdi)
  401539:       74 31                   je     40156c <bombphase_1+0x52>
  40153b:       38 4f 12                cmp    %cl,0x12(%rdi)
  40153e:       75 1e                   jne    40155e <bombphase_1+0x44>
  401540:       0f b6 57 15             movzbl 0x15(%rdi),%edx
  401544:       0f b6 47 1b             movzbl 0x1b(%rdi),%eax
  401548:       38 c2                   cmp    %al,%dl
  40154a:       74 12                   je     40155e <bombphase_1+0x44>
  40154c:       0f be ca                movsbl %dl,%ecx
  40154f:       0f be c0                movsbl %al,%eax
  401552:       8d 50 05                lea    0x5(%rax),%edx
  401555:       b8 01 00 00 00          mov    $0x1,%eax
  40155a:       39 d1                   cmp    %edx,%ecx
  40155c:       74 13                   je     401571 <bombphase_1+0x57>
  40155e:       e8 1a 09 00 00          callq  401e7d <explode_this_bomb>
  401563:       48 c7 c0 dc 16 3b f4    mov    $0xfffffffff43b16dc,%rax
  40156a:       eb 05                   jmp    401571 <bombphase_1+0x57>
  40156c:       b8 00 00 00 00          mov    $0x0,%eax
  401571:       48 83 c4 08             add    $0x8,%rsp
  401575:       c3                      retq

  bombphase_1(char *rdi, rsi, rdx, rcx)
{
  if (rdi[0] != 'f')
    goto explode;
  else if (rdi[3] != 'S')
    goto explode;
  else if (rdi[1] != '7')
    goto explode;
  else if (rdi[4] != '0')
    goto explode;
  else if (rdi[2] == '`')
    return 0;
  
explode:
  explode_this_bomb ();
  return 0xfffffffff43b16dc;
}

Dump of assembler code for function bombphase_2:
   0x000000000040162f <+0>:     push   %rbx
   0x0000000000401630 <+1>:     sub    $0x10,%rsp
   0x0000000000401634 <+5>:     mov    %rdi,%rbx
   0x0000000000401637 <+8>:     movabs $0x6e656469666e6f63,%rax
   0x0000000000401641 <+18>:    mov    %rax,(%rsp)
   0x0000000000401645 <+22>:    movw   $0x6563,0x8(%rsp)
   0x000000000040164c <+29>:    movb   $0x0,0xa(%rsp)
   0x0000000000401651 <+34>:    mov    $0xa,%edx
   0x0000000000401656 <+39>:    mov    %rsp,%rsi
   0x0000000000401659 <+42>:    callq  0x4015b5 <my_strncmp>
   0x000000000040165e <+47>:    test   %eax,%eax
   0x0000000000401660 <+49>:    jne    0x401680 <bombphase_2+81>
   0x0000000000401662 <+51>:    mov    $0x0,%eax
   0x0000000000401667 <+56>:    cmpb   $0x0,0xa(%rbx)
   0x000000000040166b <+60>:    je     0x40168c <bombphase_2+93>
   0x000000000040166d <+62>:    mov    %rbx,%rdi
   0x0000000000401670 <+65>:    callq  0x401611 <my_strlen>
   0x0000000000401675 <+70>:    cmp    $0x17,%eax
   0x0000000000401678 <+73>:    sete   %al
   0x000000000040167b <+76>:    movzbl %al,%eax
   0x000000000040167e <+79>:    jmp    0x40168c <bombphase_2+93>
   0x0000000000401680 <+81>:    callq  0x401e7d <explode_this_bomb>
   0x0000000000401685 <+86>:    mov    $0xfffffffff43b16dc,%rax
   0x000000000040168c <+93>:    add    $0x10,%rsp
   0x0000000000401690 <+97>:    pop    %rbx
   0x0000000000401691 <+98>:    retq

int
bombphase_2(char *input)
{
  char string[11] = {0x6e, 0x65, 0x64, 0x69, 0x66, 0x6e, 0x6f, 0x63, 0x65, 0x63, 0x00};
  if (strncmp (input, string, 0x0a))
    goto explode;
  else if (input[0x0a] != 0x00)
    return my_strlen (input) == 0x17;
  return 0;
explode:
  explode_this_bomb();
  return 0xfffffffff43b16dc;
}

0x0000000000401637 <+8>:    movabs $0x6e656469666e6f63,%rax

// stores the string nedifnoc into %rax
   0x0000000000401641 <+18>:    mov    %rax,(%rsp)
   0x0000000000401645 <+22>:    movw   $0x6563,0x8(%rsp)
   0x000000000040164c <+29>:    movb   $0x0,0xa(%rsp)

<+18> // relocates the string onto the stack pointer, <+22> appends 0x6563 := "ec" onto the end and <+29> adds the NULL terminator
   0x0000000000401656 <+39>:    mov    %rsp,%rsi
   0x0000000000401659 <+42>:    callq  0x4015b5 <my_strncmp>
   0x000000000040165e <+47>:    test   %eax,%eax
   0x0000000000401660 <+49>:    jne    0x401680 <bombphase_2+81>

<+39> // moves the string's address into the second parameter register rsi to prepare <+42> with my_strncmp(%rdi, %rsi) where %rdi is the user input from bombphase_2, hence comparing the string nedifnocec, then by <+49> if the string's aren't equal explode_this_bomb is called
   0x0000000000401662 <+51>:    mov    $0x0,%eax
   0x0000000000401667 <+56>:    cmpb   $0x0,0xa(%rbx)
   0x000000000040166b <+60>:    je     0x40168c <bombphase_2+93>

<+51> // prepares return code and <+56> checks that the user input string has the same length as the flag string, then if so, it succeeds and jumps from <+60> and returns a zero exit code 
like in the last phase 
   0x000000000040166d <+62>:    mov    %rbx,%rdi
   0x0000000000401670 <+65>:    callq  0x401611 <my_strlen>
   0x0000000000401675 <+70>:    cmp    $0x17,%eax
   0x0000000000401678 <+73>:    sete   %al
   0x000000000040167b <+76>:    movzbl %al,%eax
   0x000000000040167e <+79>:    jmp    0x40168c <bombphase_2+93>

// regardless of the result it jumps to the return procedure and never calls explode_this_bomb but it will return non-zero

uint64_t
bombphase_4 (char * input)
{
  strcat (%rsp + 0x30, input)

  if ( *(uint64_t*)(%rsp + 0x58) != 0 )
    return sym.explode_this_bomb ();
  else if ( *(uint32_t*)(%rsp + 0x60) != 0xb8222ae0 )
    return sym.explode_this_bomb ();
  else if ( *(uint8_t*)(%rsp + 0x50) != 0x74 )
    return sym.explode_this_bomb ();
  else if ( *(uint16_t*)(%rsp + 0x52) != 0x4a25 )
    return sym.explode_this_bomb ();
  return good ();
}

  0x0000000000401692 <+0>:       sub    $0x8,%rsp 
   0x0000000000401696 <+4>:      movzbl 0x7(%rdi),%eax
   0x000000000040169a <+8>:      test   %al,%al
   0x000000000040169c <+10>:     je     0x4016ec <bombphase_5+90>
   0x000000000040169e <+12>:     lea    0x7(%rdi),%r8
   0x00000000004016a2 <+16>:     mov    %r8,%rdx
   0x00000000004016a5 <+19>:     mov    $0x222,%esi
   0x00000000004016aa <+24>:     mov    $0x4038fc,%edi
   0x00000000004016af <+29>:     movzbl %al,%ecx
   0x00000000004016b2 <+32>:     add    %ecx,%esi
   0x00000000004016b4 <+34>:     sub    $0x5d,%eax
   0x00000000004016b7 <+37>:     mov    %eax,%ecx
   0x00000000004016b9 <+39>:     and    $0x1f,%ecx
   0x00000000004016bc <+42>:     cmp    %al,%cl
   0x00000000004016be <+44>:     jne    0x4016dc <bombphase_5+74>
   0x00000000004016c0 <+46>:     lea    0x1(%rdi),%rax
   0x00000000004016c4 <+50>:     add    $0x5d,%ecx
   0x00000000004016c7 <+53>:     cmp    (%rdi),%cl
   0x00000000004016c9 <+55>:     je     0x4016d9 <bombphase_5+71>
   0x00000000004016cb <+57>:     callq  0x401e7d <explode_this_bomb>
   0x00000000004016d0 <+62>:     mov    $0xfffffffff43b16dc,%rax
   0x00000000004016d7 <+69>:     jmp    0x401714 <bombphase_5+130>
   0x00000000004016d9 <+71>:     mov    %rax,%rdi
   0x00000000004016dc <+74>:     add    $0x1,%rdx
   0x00000000004016e0 <+78>:     movzbl (%rdx),%eax
   0x00000000004016e3 <+81>:     test   %al,%al
   0x00000000004016e5 <+83>:     jne    0x4016af <bombphase_5+29>
   0x00000000004016e7 <+85>:     cmpb   $0x0,(%rdi)
   0x00000000004016ea <+88>:     je     0x4016fa <bombphase_5+104>
   0x00000000004016ec <+90>:     callq  0x401e7d <explode_this_bomb>
   0x00000000004016f1 <+95>:     mov    $0xfffffffff43b16dc,%rax
   0x00000000004016f8 <+102>:    jmp    0x401714 <bombphase_5+130>
   0x00000000004016fa <+104>:    mov    $0x0,%eax
   0x00000000004016ff <+109>:    cmp    $0x94e,%esi
   0x0000000000401705 <+115>:    jne    0x401714 <bombphase_5+130>
   0x0000000000401707 <+117>:    sub    %r8,%rdx
   0x000000000040170a <+120>:    cmp    $0x2b,%rdx
   0x000000000040170e <+124>:    sete   %al
   0x0000000000401711 <+127>:    movzbl %al,%eax
   0x0000000000401714 <+130>:    add    $0x8,%rsp
   0x0000000000401718 <+134>:    retq

uint64_t
explode_this_bomb (void)
{
  exit (0);
  return 0;
}

uint64_t
bombphase_5 (const char * input)
{
  char * magic_string = "mazes";
  size_t char_accum = 0x222;
  size_t ms_idx = 0,
         input_idx = 0;

  if (!input[7])
    return explode_this_bomb ();

  do {
    char_accum += input[input_idx];
    if ( (input[input_idx] - 0x5d) == ( (input[input_idx] - 0x5d) & 0x1f) )
    {
      if ((input[input_idx] - 0x5d) & 0x1f + 0x5d != magic_string[ms_idx])
        return explode_this_bomb ();
      ++ms_idx;
    }
    ++input_idx;
  } while (input[input_idx]);

  if (magic_string[ms_idx])
    return explode_this_bomb ();

  if (char_accum == 0x94e)
    return strlen (input) == 0x2b;
  return 0;
}