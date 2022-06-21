var addon = require('bindings')('addon.node')

const n = 16*1024*1024
const srcLen = 4 * n
console.log("source length: ", srcLen)

var src = new Uint32Array(n)
for (let i = 0; i < src.length; i++) {
    src[i] = Math.floor(Math.random() * 1000000)
}

let dst = new Uint8Array(16*n)
let encoded = addon.VbEncode32(src, dst)
console.log("[VbEncode32] encoded length is: ", encoded, encoded/srcLen)

let check = new Uint32Array(n);
let decoded = addon.VbDecode32(dst, n, check);
console.log("[VbDecode32] decoded bytes: ", decoded);

for (let i = 0; i < n; i++) {
    if (src[i] != check[i]) {
        console.log("elements at %d not equal: %d != %d", i, src[i], check[i]);
    }
}

//---------------------------

dst = new Uint8Array(16*n)
encoded = addon.VbDEncode32(src, dst)
console.log("[VbDEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.VbD1Encode32(src, dst)
console.log("[VbD1Encode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.VbZEncode32(src, dst)
console.log("[VbZEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.VbXEncode32(src, dst)
console.log("[VbXEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.VbDdEncode32(src, dst)
console.log("[VbDdEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8Encode32(src, dst)
console.log("[V8Encode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8DEncode32(src, dst)
console.log("[V8DEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8D1Encode32(src, dst)
console.log("[V8D1Encode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8ZEncode32(src, dst)
console.log("[V8ZEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8XEncode32(src, dst)
console.log("[V8XEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NEncode32(src, dst)
console.log("[V8NEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NDEncode32(src, dst)
console.log("[V8NDEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8ND1Encode32(src, dst)
console.log("[V8ND1Encode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NZEncode32(src, dst)
console.log("[V8NZEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NEncode128v32(src, dst)
console.log("[V8NEncode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NDEncode128v32(src, dst)
console.log("[V8NDEncode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8ND1Encode128v32(src, dst)
console.log("[V8ND1Encode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NZEncode128v32(src, dst)
console.log("[V8NZEncode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NEncode256v32(src, dst)
console.log("[V8NEncode256v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NDEncode256v32(src, dst)
console.log("[V8NDEncode256v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8ND1Encode256v32(src, dst)
console.log("[V8ND1Encode256v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.V8NZEncode256v32(src, dst)
console.log("[V8NZEncode256v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.VsEncode32(src, dst)
console.log("[VsEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4NEncode32(src, dst)
console.log("[P4NEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4NEncode128v32(src, dst)
console.log("[P4NEncode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4NDEncode32(src, dst)
console.log("[P4NDEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4NDEncode128v32(src, dst)
console.log("[P4NDEncode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4ND1Encode32(src, dst)
console.log("[P4ND1Encode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4ND1Encode128v32(src, dst)
console.log("[P4ND1Encode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4NZEncode32(src, dst)
console.log("[P4NZEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.P4NZEncode128v32(src, dst)
console.log("[P4NZEncode128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitNPack32(src, dst)
console.log("[BitNPack32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitNPack128v32(src, dst)
console.log("[BitNPack128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitNDPack32(src, dst)
console.log("[BitNDPack32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitNDPack128v32(src, dst)
console.log("[BitNDPack128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitND1Pack32(src, dst)
console.log("[BitND1Pack32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitND1Pack128v32(src, dst)
console.log("[BitND1Pack128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitNZPack32(src, dst)
console.log("[BitNZPack32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.BitNZPack128v32(src, dst)
console.log("[BitNZPack128v32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.EFanoEncode32(src, dst)
console.log("[EFanoEncode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.EFano1Encode32(src, dst)
console.log("[EFano1Encode32] encoded length is: ", encoded, encoded/srcLen)

dst = new Uint8Array(16*n)
encoded = addon.EFanoEncode128v32(src, dst)
console.log("[EFanoEncode128v32] encoded length is: ", encoded, encoded/srcLen)

