/* SPDX-License-Identifier: (GPL-2.0-only or LGPL-2.1-only)
 *
 * probes/lttng-probe-kvm.c
 *
 * LTTng kvm probes.
 *
 * Copyright (C) 2010-2012 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 */

#include <linux/module.h>
#include <linux/kvm_host.h>
#include <lttng/tracer.h>
#include <lttng/kernel-version.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,1,0))
#include <kvm/iodev.h>
#else /* #if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,1,0)) */
#include <../../virt/kvm/iodev.h>
#endif /* #else #if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,1,0)) */

/*
 * Create the tracepoint static inlines from the kernel to validate that our
 * trace event macros match the kernel we run on.
 */
#include <wrapper/tracepoint.h>

#include <../../arch/x86/kvm/mmutrace.h>

#undef TRACE_INCLUDE_PATH
#undef TRACE_INCLUDE_FILE

/*
 * Create LTTng tracepoint probes.
 */
#define LTTNG_PACKAGE_BUILD
#define CREATE_TRACE_POINTS

#define TRACE_INCLUDE_PATH instrumentation/events/arch/x86/kvm
#include <instrumentation/events/arch/x86/kvm/mmutrace.h>

MODULE_LICENSE("GPL and additional rights");
MODULE_AUTHOR("Mathieu Desnoyers <mathieu.desnoyers@efficios.com>");
MODULE_DESCRIPTION("LTTng kvm mmu probes");
MODULE_VERSION(__stringify(LTTNG_MODULES_MAJOR_VERSION) "."
	__stringify(LTTNG_MODULES_MINOR_VERSION) "."
	__stringify(LTTNG_MODULES_PATCHLEVEL_VERSION)
	LTTNG_MODULES_EXTRAVERSION);
