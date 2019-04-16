#include <bolos_target.h> // we need target definitions
#if defined(TARGET_NANOX)

#include <os_io_seproxyhal.h>
#include "menu.h"
#include "getVersion.h"
#include "glyphs.h"

// Helper macro for better astyle formatting of UX_FLOW definitions
#define LINES(...) { __VA_ARGS__ }

UX_FLOW_DEF_NOCB(
        ux_idle_flow_1_step,
        bn,
        #if defined(DEVEL) || defined(HEADLESS)
        LINES(
                "Warning:",
                "DEVEL version!"
        )
        #else
        LINES(
                "Waiting for",
                "commands"
        )
        #endif
);

UX_FLOW_DEF_NOCB(
        ux_idle_flow_2_step,
        bn,
        LINES(
                "Version",
                APPVERSION
        )
);

UX_FLOW_DEF_VALID(
        ux_idle_flow_3_step,
        pb,
        os_sched_exit(-1),
        LINES(
                &C_icon_dashboard,
                "Quit"
        )
);

const ux_flow_step_t * const ux_idle_flow [] = {
	&ux_idle_flow_1_step,
	&ux_idle_flow_2_step,
	&ux_idle_flow_3_step,
	FLOW_END_STEP,
};

#endif