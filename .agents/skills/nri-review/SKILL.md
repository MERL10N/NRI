---
name: nri-review
description: Review NRI changes for merge readiness, graphics-API correctness, backend parity, validation coverage, duplication, simplification, and build risk.
---

# NRI Review

Read `../nri-coding-standard/SKILL.md` completely before reviewing. Treat it as the coding-policy checklist; this skill defines the review method.

Review exactly the target and comparison basis specified by the user. Clarify only when genuine ambiguity could change the findings.

## Map the Feature

Trace each changed public concept through:

`public API -> capabilities -> Validation -> backend entry point -> native objects/commands -> result/feedback -> destruction`

Find all declarations and call sites. Check function-table wiring, supported and unsupported backends, neutral and native paths, and the resources, indices, offsets, states, queues, ownership, and lifetimes represented by the API.

Review the whole feature neighborhood, not only the last commit or added lines.

## Correctness and Backend Parity

- Every valid advertised path must execute safely with the documented meaning.
- Capabilities, Validation, and implementation behavior must agree.
- Compare D3D12 and Vulkan resource states, access/stages, queues, ownership, synchronization, setup/reference/reconstructed pictures, offsets, feedback, and object lifetimes.
- Different native requirements are valid only when the NRI contract lets callers discover and satisfy them.
- Check zero and maximum counts, sparse or duplicate slots, aliasing, optional pointers, nonzero offsets, narrowing, partial construction, rollback, and destruction.
- Check relevant combinations of codec, encode/decode, frame type, neutral/native arguments, host/buffer sources, coincident/distinct pictures, Validation/direct use, and Agility/non-Agility.
- Verify uncertain GAPI rules with primary documentation or primary implementation sources; identify inferences.

## Duplication and Simplification

Use this pass for substantial implementation changes or when maintainability is in scope. Correctness and merge risk come first.

- Compare file-local helpers and substantial workflows across backends.
- Look for equivalent bodies with the same or different names, terminology, capitalization, or backend suffixes.
- Use backend suffixes to locate helper counterparts; backend classes and native-facing types keep their suffixes.
- Check duplication within one backend, especially capability probing versus creation, descriptor construction, codec branches, and count/check/write workflows.
- Share only genuinely backend-independent reused logic. Keep one-off and native-specific helpers local.
- Retain duplication when abstraction would worsen pointer lifetime, diagnostics, performance, or native clarity; state that reason.

## Merge Verdict

A blocker is a supported valid path that can fail, crash, access missing storage, use invalid native data, violate an undiscoverable resource-state contract, advertise unsupported behavior, break Validation or interface wiring, leak or misuse lifetime, fail a required build, or prevent a clean merge.

Incomplete functionality is non-blocking when explicitly unsupported, accurately reported, and harmless to existing NRI. ABI changes alone are not findings for v181 when recompilation is accepted.

One reachable blocker controls the verdict.

## Verification and Report

- Run `git diff --check`, check for accidental edits, and verify CRLF.
- Build every affected backend and feature gate. For Windows video merge readiness, normally cover Agility and non-Agility D3D12, Vulkan, Debug, and Release; include shared consumers such as WGPU when public/shared headers changed.
- Distinguish compilation from runtime coverage and list important untested paths.
- Review the exact final tree, not an earlier iteration.

Report findings first by severity. Give exact file/line, reachable path, violated NRI or native rule, affected backend/mode, why Validation or capabilities do not prevent it, and a concrete fix.

End with blocker and useful non-blocker counts, verification performed and omitted, and an explicit `MERGEABLE` or `NOT MERGEABLE` verdict.
