{
  description = "leetcode shell";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
    ...
  } @ inputs: let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
    llvm = pkgs.llvmPackages_18;
    lib = nixpkgs.lib;
  in {
    devShells.${system}.default =
      pkgs.mkShell
      {
        nativeBuildInputs = with pkgs; [
          clang
          clang-tools
          libclang
          libcxx
        ];

        CPATH = builtins.concatStringsSep ":" [
          (lib.makeSearchPathOutput "dev" "include" [pkgs.libcxx])
          (lib.makeSearchPath "resource-root/include" [pkgs.clang])
        ];
      };
  };
}
