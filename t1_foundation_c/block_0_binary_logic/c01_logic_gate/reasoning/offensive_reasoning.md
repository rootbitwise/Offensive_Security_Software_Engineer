# Offensive reasoning about the kind of logic gates


### XOR on the offensive side

XOR appears in shellcode, malware obfuscation,checkums, and in other techniques. The property that makes it useful
on the side is its reversibility

If you encrypt a piece of data by doing: encryption = text xor key, reversing that same operation with the same key
that was used to encrypt, text = encryption xor key, you get the text that was encrypyed, that reversibility is the 
basis of the mathematics of the most common obfuscation of malware.

Example of reversibility with a key that if you change the bits (a key that is not 0), A = 1 and key = 1.

```
Encrypt: 1 xor 1 = 0   # The encrypted is 0, different from the original  
Decrypt: 0 xor 1 = 1   # Recovers A

```

The key is never set to 0 because x xor 0 = 0, it does not encrypt anything, the 0 can come from the data not from the key
### The  xor eax, eax

The second property of xor is the reason for a pattern widely used in disassembly : A xor A = 0

```asm
xor eax, eax ; This puts the eax registry at 0, because eax xor eax is 0
```

This pattern is used instead of mov eax 0 because it takes up fewer bytes and does not introduce null bytes. This is
critical for shellcode: a null byte \0 breaks a string, and if the shellcode is a string-based exploit, with a null byte it 
breaks. When xor eax eax appears in the disassembly, it is not an encryption operation, it is putting the registry at 0.

### Manually Decoded (Phase 4)

Buffer XOR-encrypted with a single byte, key `0x2A`. Recover the plaintext manually.

```
0x62 xor 0x2A:
  0110 0010
  0010 1010
  ---------
  0100 1000 = 0x48 = 'H'

0x63 xor 0x2A:
  0110 0011
  0010 1010
  ---------
  0100 1001 = 0x49 = 'I'
```

The hidden word is HI. This is the same pattern that a malware string decoder processes byte by byte right before using the string.

### Debugging on paper: why `bits & ~bits` always yields 0 (Phase 4)

```c
result = bits & ~bits;   // Always 0
```

A bit and its inverse are always different. The AND operation of a bit with its own inverse always yields 0, for any bit. That is why the entire expression always evaluates to 0.

```text
bit | ~bit | bit & ~bit
 0  |  1   |    0
 1  |  0   |    0
```

You don't use this to flip a single bit; instead, you use `bit ^ 1` (XORing with 1 flips the bit), or for a bit at a specific position **(bits >> i) & 1**  to extract it.

### Phase 4.5 - Crack the code (partial)

Question 1: What did the developer of the **has_permission** function assume? They assumed that the mask comes from trusted code and has only a single bit set specifically, the permission being checked.

Questions 2, 3, and 4: PENDING. It is necessary to reason through what happens if the attacker controls the mask, which violation grants control rather than merely causing a crash, and how this could be exploited in a real-world operation. Close this out before finalizing.

_END OF DOCUMENTS_
