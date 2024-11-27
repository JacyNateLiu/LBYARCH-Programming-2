section .text
bits 64
default rel
global saxpy

saxpy:
    ; Parameters:
    ; RCX - pointer to the first array (X)
    ; RDX - pointer to the second array (Y)
    ; R8  - pointer to the result array (Z)
    ; R9  - n of the arrays
    ; XMM0 - float A (scalar)

    push rbp
    mov rbp, rsp

    xor r10, r10

.loop:
    cmp r10, r9               ; Compare r10 with n
    jge .done                 ; Exit loop if r10 >= n

    movss xmm1, [rcx + r10 * 4] ; Load X[i] into xmm1
    mulss xmm1, xmm0           ; Multiply X[i] by A
    addss xmm1, [rdx + r10 * 4] ; Add Y[i] to xmm1
    movss [r8 + r10 * 4], xmm1  ; Store the result in Z[i]

    inc r10
    jmp .loop

.done:
    pop rbp
    ret
