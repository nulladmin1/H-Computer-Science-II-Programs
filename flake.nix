{
  description = "programs";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    systems.url = "github:nix-systems/default";

    eightQueens = {
      url = "github:nulladmin1/eightQueens";
      inputs.nixpkgs.follows = "nixpkgs";
      inputs.systems.follows = "systems";
    };
    plague = {
      url = "github:nulladmin1/mp2ExtraCredit";
      inputs.nixpkgs.follows = "nixpkgs";
      inputs.systems.follows = "systems";
    };
  };

  outputs = {
    self,
    nixpkgs,
    systems,
    ...
  } @ inputs: let
    forEachSystem = nixpkgs.lib.genAttrs (import systems);
    pkgsFor = forEachSystem (system: import nixpkgs {inherit system;});
  in {
    formatter = forEachSystem (system: pkgsFor.${system}.alejandra);

    devShells = forEachSystem (system: {
      default = pkgsFor.${system}.mkShell {
        packages = with pkgsFor.${system}; [
          libllvm
          libgcc
          cmake
          gtest

          uncrustify
        ];
      };
    });

    packages = forEachSystem (system: {
      programs = pkgsFor.${system}.stdenv.mkDerivation {
        pname = "programs";
        version = "0.1.0";
        src = ./.;

        nativeBuildInputs = with pkgsFor.${system}; [
          cmake
        ];
        buildInputs = with pkgsFor.${system}; [
          gtest
        ];
      };
    });

    apps = forEachSystem (system: {
      fraction = {
        type = "app";
        program = "${self.packages.${system}.programs}/bin/fraction_exe";
      };

      eightQueens = inputs.eightQueens.apps.${system}.default;
      plague = inputs.plague.apps.${system}.default;
    });
  };
}
