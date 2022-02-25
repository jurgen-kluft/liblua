package liblua

import (
	xbase "github.com/jurgen-kluft/xbase/package"
	"github.com/jurgen-kluft/xcode/denv"
	xunittest "github.com/jurgen-kluft/xunittest/package"
)

// GetPackage returns the package object of 'liblua'
func GetPackage() *denv.Package {
	// Dependencies
	xunittestpkg := xunittest.GetPackage()
	xbasepkg := xbase.GetPackage()

	// The main (liblua) package
	mainpkg := denv.NewPackage("liblua")
	mainpkg.AddPackage(xunittestpkg)
	mainpkg.AddPackage(xbasepkg)

	// 'liblua' library
	mainlib := denv.SetupDefaultCppLibProject("liblua", "github.com\\jurgen-kluft\\liblua")
	mainlib.Dependencies = append(mainlib.Dependencies, xbasepkg.GetMainLib())

	// 'liblua' unittest project
	maintest := denv.SetupDefaultCppTestProject("liblua_test", "github.com\\jurgen-kluft\\liblua")
	maintest.Dependencies = append(maintest.Dependencies, xunittestpkg.GetMainLib())
	maintest.Dependencies = append(maintest.Dependencies, xbasepkg.GetMainLib())
	maintest.Dependencies = append(maintest.Dependencies, mainlib)

	mainpkg.AddMainLib(mainlib)
	mainpkg.AddUnittest(maintest)
	return mainpkg
}
