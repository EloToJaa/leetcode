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
          # leetcode-cli only reads ~/.leetcode/leetcode.toml, so install ./leetcode.toml
          # there on shell entry. It is copied, not symlinked, because `leetcode edit -l`
          # writes the config back. Cookies are read from Chrome (see ./leetcode.toml).
          shellHook = ''
            root="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
            mkdir -p "$HOME/.leetcode"
            rm -f "$HOME/.leetcode/leetcode.toml"
            sed "s|@root@|$root|g" "$root/leetcode.toml" > "$HOME/.leetcode/leetcode.toml"
          '';

          packages = with pkgs; [
            leetcode-cli
            lc
            libsecret # secret-tool: decrypts Chrome cookies via the keyring

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
