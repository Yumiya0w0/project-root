void* myMemcpy(void* dest, const void* src, size_t n) {
    uint32_t* d32 = static_cast<uint32_t*> (dest);
    const uint32_t* s32 = static_cast<const uint32_t*> (src);
    size_t words = n/4;
    for(size_t i = 0; i < words; i++)
    { d32[i] = s32[i]; }
    uint8_t* d8 = static_cast<uint8_t*> (d32+words);
    const uint8_t* s8 = static_cast<const uint8_t*> (s32+words);
    size_t remains = n%4;
    for(size_t i = 0; i < remains; i++)
    { d8[i] = s8[i]; }
}

void* myMemcpy(void* dest, const void* src, size_t n) {
    uint8_t* d = static_cast<uint8_t*>(dest);
    const uint8_t* s = static_cast<const uint8_t*>(src);

    // 階段 1：先把 d 補齊到 4-byte 對齊
    // (addr & 3) 可以拿到不對齊的偏量：1, 2, 3
    while (n > 0 && (reinterpret_cast<uintptr_t>(d) & 3) != 0) {
        *d++ = *s++;
        n--;
    }

    // 階段 2：現在 d 已經對齊 4-byte 了，開始大塊搬移
    // 注意：這裡仍假設 s 也是對齊的。若 s 不對齊，某些架構讀取 s 仍會有風險
    size_t words = n >> 2;
    for (size_t i = 0; i < words; ++i) {
        *(uint32_t*)d = *(const uint32_t*)s;
        d += 4;
        s += 4;
    }

    // 階段 3：搬移最後剩下的 byte
    size_t remains = n & 3;
    for (size_t i = 0; i < remains; ++i) {
        *d++ = *s++;
    }

    return dest;
}
