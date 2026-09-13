from splat.segtypes.common.bss import CommonSegBss

class N64SegBss_legacy(CommonSegBss):
    """Keep the original $ROM symbol suffix when subdividing a BSS section."""

    def configure_disassembler_section(self, disassembler_section):
        section = disassembler_section.get_section()
        # BSS has no ROM bytes. Use the parent segment's linear address mapping
        # for symbol names, independent of where this BSS slice starts.
        rom_start = self.get_most_parent().ram_to_rom(self.vram_start)
        assert rom_start is not None
        section.vromStart = rom_start
        section.vromEnd = section.vromStart
