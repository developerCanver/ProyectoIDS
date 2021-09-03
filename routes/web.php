<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\Prequisitos;
use App\Http\Controllers\InstalarDaq;
use App\Http\Controllers\InstalarSnort;
use App\Http\Controllers\Actualizar;
use App\Http\Controllers\GestionarReglas;
use App\Http\Controllers\InstalarReglasController;
use App\Http\Controllers\Librerias;
use App\Http\Controllers\Paquetes;
use App\Http\Controllers\Rules;
use App\Http\Controllers\Red;
use App\Models\Btn;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/






Route::get('/', function () {
    $consulta = Btn::first();

    return view('inicio',[
        'consulta'    => $consulta,
    ]);
})->middleware('auth');



Route::get('/correrRegla', function () {
    $consulta = Btn::first();

    return view('correrRegla',[
        'consulta'    => $consulta,
    ]);

})->middleware('auth');


Route::get('/rules',                            [Rules::class, 'index'])->middleware('auth');
Route::post('regla',                            [Rules::class, 'store'])->middleware('auth');
Route::get('/instalardaq',                      [InstalarDaq::class, 'index'])->middleware('auth');
Route::get('/instalarsnort',                    [InstalarSnort::class, 'index'])->middleware('auth');

Route::get('/actualizar',                       [Actualizar::class, 'index'])->middleware('auth');
Route::get('/librerias',                        [Librerias::class, 'index'])->middleware('auth');
Route::get('/descargar',                        [Paquetes::class, 'index'])->middleware('auth');
Route::get('/requisitos',                       [Prequisitos::class, 'index'])->middleware('auth');
Route::get('/configurarweb',                    [Red::class, 'index'])->middleware('auth');

Route::get('/instalarReglas',                   [InstalarReglasController::class, 'index'])->middleware('auth');
Route::get('instalarReglas/activar/{id}',          [InstalarReglasController::class, 'activar']);
Route::get('instalarReglas/descativar/{id}',          [InstalarReglasController::class, 'descativar']);


Route::get('/gestionarReglas',                   [GestionarReglas::class, 'index']);
Route::post('/gestionarReglas/store',             [GestionarReglas::class, 'store']);


Route::get('/snorby', function () {
  
    return view('snorby');

})->middleware('auth');


Route::middleware(['auth:sanctum', 'verified'])->get('/dashboard', function () {
    return view('dashboard');
})->name('dashboard');
