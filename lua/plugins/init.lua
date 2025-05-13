local lazy = require "lazy"
return {
  {
    "stevearc/conform.nvim",
    -- event = 'BufWritePre', -- uncomment for format on save
    opts = require "configs.conform",
  },

  -- These are some examples, uncomment them if you want to see them work!
  {
    "neovim/nvim-lspconfig",
    config = function()
      require "configs.lspconfig"
    end,
  },
  {
    "nvim-tree/nvim-tree.lua",
    opts = function()
      return require "configs.nvimtree"
    end,
  },
  -- add plugins
  {
    "folke/noice.nvim",
    lazy = false,
    opts = {
      -- add any options here
      lsp = {
        progress = {
          enabled = false,
        },
        signature = {
          enabled = false,
        },
      },
    },
    dependencies = {
      -- if you lazy-load any plugin below, make sure to add proper `module="..."` entries
      "MunifTanjim/nui.nvim",
      -- OPTIONAL:
      --   `nvim-notify` is only needed, if you want to use the notification view.
      --   If not available, we use `mini` as the fallback
      -- "rcarriga/nvim-notify",
    },
  },
  {
    "folke/which-key.nvim",
    enabled = false,
  },
  {
    "nvim-telescope/telescope-file-browser.nvim",
    dependencies = { "nvim-telescope/telescope.nvim", "nvim-lua/plenary.nvim" },
  },
  {
    "folke/flash.nvim",
    event = "VeryLazy",
    opts = require "configs.flash",
  },
  {
    "HiPhish/rainbow-delimiters.nvim",
    event = "BufRead",
    -- lazy = false,
  },
  {
    "nvchad/volt",
    lazy = true,
  },
  {
    "nvchad/menu",
    lazy = true,
  },
  { import = "nvchad.blink.lazyspec" },
}
