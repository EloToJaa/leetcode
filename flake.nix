{
  description = "LeetCode solutions";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        lc = pkgs.writeShellScriptBin "lc" ''exec ${pkgs.leetcode-cli}/bin/leetcode "$@"'';
      in
      {
        devShells.default = pkgs.mkShell {
          # leetcode-cli only reads ~/.leetcode/leetcode.toml, so write it on shell entry.
          # Cookies are not stored here: leetcode-cli reads them from the browser,
          # or from LEETCODE_CSRF / LEETCODE_SESSION env vars.
          shellHook = ''
            root="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
            mkdir -p "$HOME/.leetcode"
            rm -f "$HOME/.leetcode/leetcode.toml"
            cat > "$HOME/.leetcode/leetcode.toml" <<EOF
            [code]
            editor = "nvim"
            lang = "python3"
            comment_leading = "#"
            comment_problem_desc = true
            test = true

            [cookies]
            csrf = ""
            session = ""
            site = "leetcode.com"

            [storage]
            cache = "problems.db"
            code = "$root"
            root = "~/.leetcode"
            scripts = "$root/scripts"
            EOF
          '';

          packages = with pkgs; [
            leetcode-cli
            lc

            # Python
            python3
            pyright
            ruff

            # C++
            gcc
            clang-tools
          ];
        };
      }
    );
}
