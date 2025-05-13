local options = {
  formatters_by_ft = {
    lua = { "stylua" },
    c = {"clangd_format"},
    cpp = {"clangd_format"},
    cc = {"clangd_format"},
    h = {"clangd_format"},
    hpp = {"clangd_format"},
    zig = {"zigfmt"}
    -- css = { "prettier" },
    -- html = { "prettier" },
  },

  -- format_on_save = {
  --   -- These options will be passed to conform.format()
  --   timeout_ms = 500,
  --   lsp_fallback = true,
  -- },
}

return options
